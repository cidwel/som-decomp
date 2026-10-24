.setcpu "65816"
.segment "CODE"
.org $72BE
map_control_0e72be:
    .byte $E1 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
