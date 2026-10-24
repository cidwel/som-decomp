.setcpu "65816"
.segment "CODE"
.org $9253
map_control_0c9253:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
