.setcpu "65816"
.segment "CODE"
.org $729C
map_control_0f729c:
    .byte $E2 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
