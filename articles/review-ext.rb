module ReVIEW
  module LATEXBuilderOverride
    def result
      super.gsub('{equation*}', '{equation}')
    end
  end

  class LATEXBuilder
    prepend LATEXBuilderOverride
  end
end