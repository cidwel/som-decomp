.setcpu "65816"
.segment "CODE"
.org $223C
map_control_0c223c:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
