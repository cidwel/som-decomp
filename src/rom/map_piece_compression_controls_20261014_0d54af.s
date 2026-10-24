.setcpu "65816"
.segment "CODE"
.org $54AF
map_control_0d54af:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
