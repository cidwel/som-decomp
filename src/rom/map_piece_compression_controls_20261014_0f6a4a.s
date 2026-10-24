.setcpu "65816"
.segment "CODE"
.org $6A4A
map_control_0f6a4a:
    .byte $E4 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E1 ; previous-row copy count
