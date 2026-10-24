.setcpu "65816"
.segment "CODE"
.org $D6EC
map_control_0ed6ec:
    .byte $E1 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
