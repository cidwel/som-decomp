.setcpu "65816"
.segment "CODE"
.org $0805
map_control_0e0805:
    .byte $E2 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
