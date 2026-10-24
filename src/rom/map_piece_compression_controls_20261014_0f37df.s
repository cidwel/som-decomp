.setcpu "65816"
.segment "CODE"
.org $37DF
map_control_0f37df:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
