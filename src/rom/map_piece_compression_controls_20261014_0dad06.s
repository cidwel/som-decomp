.setcpu "65816"
.segment "CODE"
.org $AD06
map_control_0dad06:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $4B ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $DF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
