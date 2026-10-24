.setcpu "65816"
.segment "CODE"
.org $E246
map_control_0ee246:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
