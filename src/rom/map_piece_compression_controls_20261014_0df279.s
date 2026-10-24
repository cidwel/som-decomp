.setcpu "65816"
.segment "CODE"
.org $F279
map_control_0df279:
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
    .byte $E1 ; previous-row copy count
