.setcpu "65816"
.segment "CODE"
.org $42E7
map_control_0f42e7:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
