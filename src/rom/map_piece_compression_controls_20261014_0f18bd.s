.setcpu "65816"
.segment "CODE"
.org $18BD
map_control_0f18bd:
    .byte $EE ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E7 ; previous-row copy count
