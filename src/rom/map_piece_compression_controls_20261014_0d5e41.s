.setcpu "65816"
.segment "CODE"
.org $5E41
map_control_0d5e41:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
