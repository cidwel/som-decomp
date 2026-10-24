.setcpu "65816"
.segment "CODE"
.org $47B4
map_control_0e47b4:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
