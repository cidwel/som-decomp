.setcpu "65816"
.segment "CODE"
.org $9FA9
map_control_0e9fa9:
    .byte $E1 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
