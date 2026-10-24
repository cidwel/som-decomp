.setcpu "65816"
.segment "CODE"
.org $FDDE
map_control_0efdde:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
