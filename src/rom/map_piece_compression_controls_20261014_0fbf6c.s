.setcpu "65816"
.segment "CODE"
.org $BF6C
map_control_0fbf6c:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
