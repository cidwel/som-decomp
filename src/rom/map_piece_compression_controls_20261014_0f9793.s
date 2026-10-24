.setcpu "65816"
.segment "CODE"
.org $9793
map_control_0f9793:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
