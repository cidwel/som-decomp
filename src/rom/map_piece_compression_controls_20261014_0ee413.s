.setcpu "65816"
.segment "CODE"
.org $E413
map_control_0ee413:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
