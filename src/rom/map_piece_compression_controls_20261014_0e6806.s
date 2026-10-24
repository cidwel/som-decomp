.setcpu "65816"
.segment "CODE"
.org $6806
map_control_0e6806:
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
