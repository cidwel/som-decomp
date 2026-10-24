.setcpu "65816"
.segment "CODE"
.org $F453
map_control_0df453:
    .byte $E3 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
