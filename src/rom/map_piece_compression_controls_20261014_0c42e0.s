.setcpu "65816"
.segment "CODE"
.org $42E0
map_control_0c42e0:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
