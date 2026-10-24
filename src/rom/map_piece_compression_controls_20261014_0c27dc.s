.setcpu "65816"
.segment "CODE"
.org $27DC
map_control_0c27dc:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
