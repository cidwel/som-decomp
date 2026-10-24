.setcpu "65816"
.segment "CODE"
.org $E731
map_control_0ee731:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
