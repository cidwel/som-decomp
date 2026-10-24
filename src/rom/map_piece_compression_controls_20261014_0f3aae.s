.setcpu "65816"
.segment "CODE"
.org $3AAE
map_control_0f3aae:
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
