.setcpu "65816"
.segment "CODE"
.org $B7EC
map_control_0eb7ec:
    .byte $E0 ; previous-row copy escape
    .byte $97 ; row-distance/count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
