.setcpu "65816"
.segment "CODE"
.org $A323
map_control_0ea323:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
