.setcpu "65816"
.segment "CODE"
.org $BFEA
map_control_0fbfea:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
