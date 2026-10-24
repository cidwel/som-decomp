.setcpu "65816"
.segment "CODE"
.org $B648
map_control_0eb648:
    .byte $E2 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
