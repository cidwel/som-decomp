.setcpu "65816"
.segment "CODE"
.org $204A
map_control_0f204a:
    .byte $F1 ; progressive-copy count
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
