; Register-width/shadow-alias selectors and 38 native PPU initialization commands.
.setcpu "65816"
.segment "CODE"
.org $FC8E
map_spellcasting_numeric_source_20261013_register_modes:
    .byte $00, $00, $01, $00, $5C, $00, $00, $00, $00, $00, $00, $00, $00
    .byte $40, $42, $44, $46, $48, $4A, $4C, $4E, $00, $01, $00, $01, $00
    .byte $00, $50, $52, $54, $56, $58, $5A, $00, $5E, $00, $00, $00, $00
    .byte $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
.macro spell_register_default register_offset, initial_value
    .byte register_offset, initial_value
.endmacro
map_spellcasting_numeric_source_20261013_default_register_commands:
    spell_register_default $00, $8F
    spell_register_default $01, $00
    spell_register_default $02, $00
    spell_register_default $05, $09
    spell_register_default $06, $00
    spell_register_default $07, $00
    spell_register_default $08, $00
    spell_register_default $09, $00
    spell_register_default $0A, $00
    spell_register_default $0B, $00
    spell_register_default $0C, $00
    spell_register_default $0D, $00
    spell_register_default $0E, $00
    spell_register_default $0F, $00
    spell_register_default $10, $00
    spell_register_default $11, $00
    spell_register_default $12, $00
    spell_register_default $13, $00
    spell_register_default $14, $00
    spell_register_default $15, $80
    spell_register_default $1A, $00
    spell_register_default $23, $00
    spell_register_default $24, $00
    spell_register_default $25, $00
    spell_register_default $26, $00
    spell_register_default $27, $00
    spell_register_default $28, $00
    spell_register_default $29, $00
    spell_register_default $2A, $00
    spell_register_default $2B, $00
    spell_register_default $2C, $00
    spell_register_default $2D, $00
    spell_register_default $2E, $00
    spell_register_default $2F, $00
    spell_register_default $30, $30
    spell_register_default $31, $00
    spell_register_default $32, $E0
    spell_register_default $33, $00
