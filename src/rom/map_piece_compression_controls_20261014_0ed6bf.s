.setcpu "65816"
.segment "CODE"
.org $D6BF
map_control_0ed6bf:
    .byte $E1 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E7 ; previous-row copy count
