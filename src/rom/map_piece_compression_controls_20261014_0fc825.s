.setcpu "65816"
.segment "CODE"
.org $C825
map_control_0fc825:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
