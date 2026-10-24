.setcpu "65816"
.segment "CODE"
.org $88BE
map_control_0f88be:
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E3 ; previous-row copy count
