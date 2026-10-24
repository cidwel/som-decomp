; Native state-command fields; docs/boss-state-command-numeric.md.
.macro boss_state_end
    .byte $FF
.endmacro
.macro boss_state_anim arg1
    .byte $00
    .word arg1
.endmacro
.macro boss_state_frames arg1, arg2, arg3, arg4, arg5, arg6
    .byte $01
    .word arg1, arg2, arg3, arg4, arg5, arg6
.endmacro
.macro boss_state_speed90 arg1
    .byte $02
    .word arg1
.endmacro
.macro boss_state_f48 arg1
    .byte $03
    .word arg1
.endmacro
.macro boss_state_f4a arg1
    .byte $04
    .word arg1
.endmacro
.macro boss_state_duration14 arg1
    .byte $05
    .word arg1
.endmacro
.macro boss_state_set98_40
    .byte $06
.endmacro
.macro boss_state_set98_80
    .byte $07
.endmacro
.macro boss_state_tog98_40
    .byte $08
.endmacro
.macro boss_state_tog98_80
    .byte $09
.endmacro
.macro boss_state_clr98_40
    .byte $0A
.endmacro
.macro boss_state_clr98_80
    .byte $0B
.endmacro
.macro boss_state_set_e1e3 arg1
    .byte $0C
    .word arg1
.endmacro
.macro boss_state_pal arg1
    .byte $0D
    .word arg1
.endmacro
.macro boss_state_spell arg1
    .byte $0E
    .word arg1
.endmacro
.macro boss_state_spawn arg1, arg2, arg3
    .byte $0F
    .byte arg1, arg2, arg3
.endmacro
.macro boss_state_callnative arg1
    .byte $10
    .word arg1
.endmacro
.macro boss_state_store arg1, arg2
    .byte $11
    .word arg1, arg2
.endmacro
.macro boss_state_c18003 arg1
    .byte $12
    .word arg1
.endmacro
.macro boss_state_c0_006c arg1
    .byte $13
    .word arg1
.endmacro
.macro boss_state_call30e3 arg1
    .byte $14
    .word arg1
.endmacro
.macro boss_state_jump arg1
    .byte $15
    .word arg1
.endmacro
