.setcpu "65816"
.segment "CODE"
.org $DDE2
map_control_0edde2:
    .byte $E2 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $89 ; distance low bit/count
