.setcpu "65816"
.segment "CODE"
.org $AA6C
map_control_0faa6c:
    .byte $E2 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
