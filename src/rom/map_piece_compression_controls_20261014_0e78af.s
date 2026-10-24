.setcpu "65816"
.segment "CODE"
.org $78AF
map_control_0e78af:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
