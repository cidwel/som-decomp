.setcpu "65816"
.segment "CODE"
.org $C079
map_control_0fc079:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
