.setcpu "65816"
.segment "CODE"
.org $5D00
map_control_0f5d00:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
