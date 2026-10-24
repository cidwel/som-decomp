.setcpu "65816"
.segment "CODE"
.org $64C9
map_control_0f64c9:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
