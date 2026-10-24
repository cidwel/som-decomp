.setcpu "65816"
.segment "CODE"
.org $162A
map_control_0c162a:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
