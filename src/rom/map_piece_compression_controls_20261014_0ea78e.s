.setcpu "65816"
.segment "CODE"
.org $A78E
map_control_0ea78e:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E3 ; previous-row copy count
