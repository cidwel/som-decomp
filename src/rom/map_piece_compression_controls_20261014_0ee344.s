.setcpu "65816"
.segment "CODE"
.org $E344
map_control_0ee344:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
