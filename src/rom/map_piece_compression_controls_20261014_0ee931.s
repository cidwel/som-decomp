.setcpu "65816"
.segment "CODE"
.org $E931
map_control_0ee931:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
