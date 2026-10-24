.setcpu "65816"
.segment "CODE"
.org $9DF1
map_control_0d9df1:
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
