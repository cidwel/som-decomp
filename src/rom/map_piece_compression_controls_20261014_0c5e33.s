.setcpu "65816"
.segment "CODE"
.org $5E33
map_control_0c5e33:
    .byte $F2 ; progressive-copy count
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
