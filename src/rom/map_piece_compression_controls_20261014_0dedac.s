.setcpu "65816"
.segment "CODE"
.org $EDAC
map_control_0dedac:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $9E ; row-distance/count
