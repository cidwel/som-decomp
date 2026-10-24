.setcpu "65816"
.segment "CODE"
.org $555B
map_control_0e555b:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E7 ; previous-row copy count
