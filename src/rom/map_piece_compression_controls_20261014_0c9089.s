.setcpu "65816"
.segment "CODE"
.org $9089
map_control_0c9089:
    .byte $E8 ; backreference distance high bits
    .byte $9F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
