.setcpu "65816"
.segment "CODE"
.org $C054
map_control_0fc054:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
