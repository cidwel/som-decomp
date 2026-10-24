.setcpu "65816"
.segment "CODE"
.org $7719
map_control_0c7719:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
