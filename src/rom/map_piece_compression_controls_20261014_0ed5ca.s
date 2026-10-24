.setcpu "65816"
.segment "CODE"
.org $D5CA
map_control_0ed5ca:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $51 ; row-distance/count
