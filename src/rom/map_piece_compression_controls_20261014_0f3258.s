.setcpu "65816"
.segment "CODE"
.org $3258
map_control_0f3258:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
