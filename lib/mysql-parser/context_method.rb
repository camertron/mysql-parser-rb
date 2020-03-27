module MySqlParser
  class ContextMethod
    RULE_METHODS = %w(enterRule exitRule).freeze

    attr_reader :name, :raw_args, :context

    def initialize(name, raw_args, context)
      @name = name
      @raw_args = raw_args
      @context = context
    end

    def args
      @args ||= raw_args.split(',').map do |arg|
        ContextMethodArg.new(arg.strip)
      end
    end

    def fetches_token?
      name.upcase == name
    end

    def rule?
      RULE_METHODS.include?(name)
    end

    def constructor?
      name == context.name
    end
  end
end
